#include <iostream>

#include <ruby.h>

extern "C"
{

namespace
{

VALUE file_stream_open(VALUE self, VALUE filename)
{
    std::cout << "OPEN " << StringValuePtr(filename) << std::endl;
    return self;
}

VALUE file_stream_close(VALUE self)
{
    std::cout << "CLOSE" << std::endl;
    return self;
}

void Init_file_stream()
{
    VALUE module = rb_define_module("FileStream");
    rb_define_singleton_method(module, "open", RUBY_METHOD_FUNC(file_stream_open), 1);
    rb_define_singleton_method(module, "close", RUBY_METHOD_FUNC(file_stream_close), 0);
}

} // namespace

} // extern "C"
