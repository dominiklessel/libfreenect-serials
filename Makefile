.PHONY: app deviceLister

app:
	mkdir -p bin && \
	g++ \
		`pkg-config libfreenect libusb-1.0 --cflags` \
		`pkg-config libfreenect libusb-1.0 --libs` \
		-o ./bin/readSerials \
		./_libfreenect-serials.cpp