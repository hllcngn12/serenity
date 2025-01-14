MACOSFLAGS = -Wno-empty-body \
		-Wno-unused-value
serenity:
	gcc $(MACOSFLAGS) -oserenity src/*.c -Isrc -lncurses
clean:
	rm serenity.exe serenity.exe.stackdump
.PHONY: serenity
