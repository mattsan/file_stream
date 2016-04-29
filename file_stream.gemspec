# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'file_stream/version'

Gem::Specification.new do |spec|
  spec.name          = "file_stream"
  spec.version       = FileStream::VERSION
  spec.authors       = ["Eiji MATSUMOTO"]
  spec.email         = ["e.mattsan@gmail.com"]

  spec.summary       = %q{use std::fstream on C++ from Ruby}
  spec.description   = %q{use std::fstream on C++ from Ruby}
  spec.homepage      = "https://github.com/mattsan"
  spec.license       = "MIT"

  if spec.respond_to?(:metadata)
    spec.metadata['allowed_push_host'] = 'http://mygemserver.com'
  else
    raise "RubyGems 2.0 or newer is required to protect against public gem pushes."
  end

  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.11"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec", "~> 3.0"

  spec.extensions    = ["ext/file_stream/extconf.rb"]
end
