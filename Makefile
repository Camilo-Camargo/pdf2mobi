run:
	cc -o src/main src/main.c -lm -lz third_party/pdfio/libpdfio.a && ./src/main ./test/programming_ground_up.pdf
clean:
	rm -rf src/main
