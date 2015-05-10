import xml.sax
import math

boxSize = 120
counter = 0
out_str = ""

class SvgHandler(xml.sax.ContentHandler) :
	def startElement(self, name, attrs):
		global counter
		global boxSize
		global out_str

		if name == "path":
			parts = attrs["d"].split(' ')[1:-1]
			raw = []

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

			lx = int(raw[0][0])
			ly = int(raw[0][1])
			rw = int(raw[0][0])			
			rh = int(raw[0][1])				

			for item in raw:
				lx = min(lx, item[0])
				ly = min(ly, item[1])
				rw = max(rw, item[0])
				rh = max(rh, item[1])												

			scale = 1#float(boxSize) / float(rw)
			out_sub_str = ""
			sum_x = 0
			sum_y = 0
			for item in raw:
				out_x = int((item[0]) * scale)
				out_y = int((item[1]) * scale)
				sum_x += out_x
				sum_y += out_y
				out_sub_str += "{" + str(sum_x - lx) + "," + str(sum_y - ly) + "}, "
			out_sub_str = out_sub_str[:-2]

			out_str += "static const GPathInfo KANA_" + str(counter) + "= {\n    .num_points = " + str(len(raw))
			out_str += ",\n    .points = (GPoint[]) {" + out_sub_str + "}\n};\n"

			counter += 1

parser = xml.sax.make_parser()
parser.setContentHandler(SvgHandler())
parser.parse(open("katakana.svg", "r"))

f = open("kana_out.txt", "w")
f.write(out_str)
f.close()