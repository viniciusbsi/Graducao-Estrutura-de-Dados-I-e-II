# -*- coding: utf-8 -*-

arquivo_h = 'entrada.h'
arquivo_txt = 'entrada_inicial.txt'
with open(arquivo_h, 'r+a') as entrada_h:
	print (entrada_h.read())
	i = 0
	with open(arquivo_txt, 'r') as entrada_txt:
		for row in entrada_txt.readlines()[1:]:
			row = [int(numero) for numero in row.strip('\n').split(' ')]
			if i == 418:
				row = ('{%d,%d,%d}};'% (row[0],row[1],row[2]))
			else:
				row = ('{%d,%d,%d},\n'% (row[0],row[1],row[2]))
			i+=1
			entrada_h.write(str(row))
