import xml.sax
import math

boxSize = 100
out_str = ""
glyph_init = ""
glyph_def = ""
groupStarted = False
grouped = ""
paths_len = 0
groupsDeep = 0
total_glyph_num = 0
prefix = "katakana"
PREF = "KANA"

file_prefix = "#include <pebble.h>\n"
file_prefix += "#include \"kana_app_glyphs.h\"\n\n"
file_prefix += "Glyph kana_app_katakana_glyphs[GLYPHS_NUM];\n\n"
file_prefix += "Glyph kana_app_hiragana_glyphs[GLYPHS_NUM];\n\n"

class SvgHandler(xml.sax.ContentHandler) :	

	def startElement(self, name, attrs):		
		global boxSize		
		global groupStarted
		global grouped
		global glyph_def
		global glyph_init
		global paths_len	
		global total_glyph_num
		global groupsDeep

		if name == "g":
			groupsDeep += 1
			if groupsDeep > 1:
				groupStarted = True
				grouped = ""
				paths_len = 0
		elif name == "path":
			parts = attrs["d"].split(' ')[1:-1]
			raw = []
			translated = []

			first = True
			for item in parts:
				coords = item.split(",")
				x = int(float(coords[0]))
				y = int(float(coords[1]))				
				if first:
					x = 0
					y = 0
				first = False
				raw.append([x, y])

			
			out_sub_str = ""
			sum_x = 0
			sum_y = 0
			for item in raw:				 
				sum_x += item[0]
				sum_y += item[1]

				translated.append([sum_x, sum_y])

			lx = int(translated[0][0])
			ly = int(translated[0][1])
			rw = int(translated[0][0])			
			rh = int(translated[0][1])				

			for item in translated:
				lx = min(lx, item[0])
				ly = min(ly, item[1])
				rw = max(rw, item[0])
				rh = max(rh, item[1])

			rw = rw - lx
			rh = rh - ly

			scale = float(boxSize) / float(rw)
			for item in translated:
				out_sub_str += "{" + str(int(item[0] - lx) * scale)
				out_sub_str += "," + str(int(item[1] - ly) * scale) + "}, "
			out_sub_str = out_sub_str[:-2]

			if not groupStarted:
				paths_len = 0

			glyph_def += "static const GPathInfo GLYPH_"+PREF+"_" + str(total_glyph_num) + "_" + str(paths_len) +" = \n"
			glyph_def += "{\n"
			glyph_def += "    .num_points = " + str(len(raw)) +",\n"
			glyph_def += "    .points = (GPoint[]) {" + out_sub_str + "}\n"
			glyph_def += "};\n\n"			

			if groupStarted:
				paths_len += 1				
			else:				
				paths_len = 1
				groupsDeep += 1
				self.endElement("g")						

	def endElement(self, name):		
		global boxSize		
		global groupStarted
		global grouped
		global paths_len
		global total_glyph_num
		global glyph_def
		global glyph_init
		global groupsDeep

		if name == "g":			
			if groupsDeep > 1:
				groupStarted = False
				if paths_len > 0:				
					array_prefix = "kana_app_"+prefix+"_glyphs[" + str(total_glyph_num) + "]" 
					glyph_init += array_prefix + ".size = " + str(paths_len) +";\n"
					
					for i in range(0, paths_len):
						glyph_init += array_prefix + ".glyph_path["+str(i)+"] = "
						glyph_init += "&GLYPH_"+PREF+"_"+str(total_glyph_num)+"_"+str(i)+";\n"

					glyph_init += "\n"
					
					total_glyph_num += 1

			groupsDeep -= 1

parser = xml.sax.make_parser()
parser.setContentHandler(SvgHandler())

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