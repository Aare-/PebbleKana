import xml.sax
import math

boxSize = 80
out_str = ""
glyph_init = ""
glyph_def = ""
groupStarted = False
grouped = ""
groupsDeep = 0
total_glyph_num = 0
prefix = "katakana"
PREF = "KANA"
maxGlyphElements = 0

file_prefix = "#include <pebble.h>\n"
file_prefix += "#include \"kana_app_glyphs.h\"\n\n"
file_prefix += "Glyph kana_app_katakana_glyphs[GLYPHS_NUM];\n\n"
file_prefix += "Glyph kana_app_hiragana_glyphs[GLYPHS_NUM];\n\n"

class SvgHandler(xml.sax.ContentHandler) :		

	def startElement(self, name, attrs):				
		global groupStarted
		global grouped
		global glyph_def
		global glyph_init
		global total_glyph_num
		global groupsDeep
		global prefix
		global maxGlyphElements

		if name == "g":
			groupsDeep += 1
			if groupsDeep > 1:
				groupStarted = True
				grouped = ""

				self.rawPosCache = []
		elif name == "path":
			if not groupStarted:
				grouped = ""
				self.rawPosCache = []
				groupsDeep += 1

			parts = attrs["d"].split(' ')[1:-1]

			raw = []
			for item in parts:
				coords = item.split(",")
				x = int(float(coords[0]))
				y = int(float(coords[1]))
				raw.append([x, y])
			
			sum_x = sum_y = 0			
			rawPos = []
			for item in raw:				 
				sum_x += item[0]
				sum_y += item[1]

				rawPos.append([sum_x, sum_y])

			self.rawPosCache.append(rawPos)		

			if not groupStarted:
				groupsDeep += 1
				self.endElement("g")						

	def endElement(self, name):		
		global boxSize		
		global groupStarted
		global grouped
		global total_glyph_num
		global glyph_def
		global glyph_init
		global groupsDeep
		global prefix
		global maxGlyphElements

		if name == "g":			
			if groupsDeep > 1:
				groupStarted = False
				if len(self.rawPosCache) > 0:	
					lx = int(self.rawPosCache[0][0][0])
					ly = int(self.rawPosCache[0][0][1])
					rw = int(self.rawPosCache[0][0][0])			
					rh = int(self.rawPosCache[0][0][1])				

					for glyph in self.rawPosCache:
						for item in glyph:
							lx = min(lx, item[0])
							ly = min(ly, item[1])
							rw = max(rw, item[0])
							rh = max(rh, item[1])

					rw = rw - lx
					rh = rh - ly
					scale = min(float(boxSize) / float(rw), float(boxSize) / float(rh))

					mov_y = int((168 - rh * scale) / 2)
					mov_x = int((boxSize - rw * scale) / 2)

					ctr = 0
					for glyph in self.rawPosCache:
						out_sub_str = ""
						for item in glyph:
							out_sub_str += "{" + str(int(item[0] - lx) * scale + mov_x)
							out_sub_str += "," + str(int(item[1] - ly) * scale + mov_y) + "}, "				
						out_sub_str = out_sub_str[:-2]

						glyph_def += "static const GPathInfo GLYPH_"+PREF+"_" + str(total_glyph_num) + "_" + str(str(ctr)) +" = \n"
						glyph_def += "{\n"
						glyph_def += "    .num_points = " + str(len(glyph)) +",\n"
						glyph_def += "    .points = (GPoint[]) {" + out_sub_str + "}\n"
						glyph_def += "};\n\n"	

						ctr += 1


					array_prefix = "kana_app_"+prefix+"_glyphs[" + str(total_glyph_num) + "]" 
					glyph_init += array_prefix + ".size = " + str(len(self.rawPosCache)) +";\n"
					
					for i in range(0, len(self.rawPosCache)):
						glyph_init += array_prefix + ".glyph_path["+str(i)+"] = "
						glyph_init += "&GLYPH_"+PREF+"_"+str(total_glyph_num)+"_"+str(i)+";\n"

					glyph_init += "\n"
					
					total_glyph_num += 1
					maxGlyphElements = max(len(self.rawPosCache), maxGlyphElements)

			groupsDeep -= 1

handler = SvgHandler()
parser = xml.sax.make_parser()
parser.setContentHandler(handler)

total_glyph_num = 0
prefix = "katakana"
PREF = "KANA"
parser.parse(open("katakana.svg", "r"))

sep = "/***************************/\n"
sep += "/******** SEPARATOR ********/\n"
sep += "/***************************/\n\n"

glyph_def += sep
glyph_init += sep

total_glyph_num = 0
prefix = "hiragana"
PREF = "HIRA"
parser.parse(open("hiragana.svg", "r"))

out_str = file_prefix + glyph_def
out_str += "void kana_app_glyphs_init() \n{\n" + glyph_init + "}\n"

f = open("../src/kana_app_glyphs.c", "w")
#out_str = "#define GLYPHS_NUM "+str(total_glyph_num)+"\n\n----------\n\n" + out_str
f.write(out_str)
f.close()

print "max len: " + str(maxGlyphElements)