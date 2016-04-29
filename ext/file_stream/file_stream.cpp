#include <iostream>
#include <fstream>
#include <string>

#include <ruby.h>

extern "C"
{

namespace
{

struct Stream
{
    std::ifstream* source;

    static Stream* open(const std::string& filename)
    {
        Stream* stream = new Stream;
        stream->source = new std::ifstream(filename);
        return stream;
    }

    static void close(Stream* stream)
    {
        delete stream->source;
        delete stream;
    }
};

VALUE file_stream_open(VALUE self, VALUE filename)
{
    std::cout << "OPEN" << std::endl;
    Stream* stream = Stream::open(StringValuePtr(filename));
    return Data_Wrap_Struct(self, 0, Stream::close, stream);
}

VALUE file_stream_close(VALUE self)
{
    std::cout << "CLOSE" << std::endl;
    return self;
}

void Init_file_stream()
{
    VALUE stream = rb_define_class("FileStream", rb_cObject);
    rb_define_singleton_method(stream, "open", RUBY_METHOD_FUNC(file_stream_open), 1);
    rb_define_method(stream, "close", RUBY_METHOD_FUNC(file_stream_close), 0);
}

} // namespace

} // extern "C"
