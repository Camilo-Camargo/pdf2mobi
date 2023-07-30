run:
	cc -o src/main src/main.c -lm -lz third_party/pdfio/libpdfio.a && ./src/main
clean:
	rm -rf src/main
