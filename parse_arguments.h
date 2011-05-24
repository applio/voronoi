/* The MIT License

Copyright (c) 2011 Sahab Yazdani

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H

#include <string>
#include <vector>
#include <memory>

struct StipplingParameters {
	enum StippleAlgorithm {
		CPU,
		GPU
	};

	StippleAlgorithm algorithm;
	std::string inputFile;
	std::string outputFile;
	unsigned int points;
	float threshold;
	bool createLogs;
	bool useColour;

	StipplingParameters() {
		algorithm = CPU;
		points = 4000;
		threshold = 0.1f;
		createLogs = false;
		useColour = false;
	}
};

std::auto_ptr<StipplingParameters> parseArguments( int argc, char *argv[] );

#endif // PARSE_ARGUMENTS_H