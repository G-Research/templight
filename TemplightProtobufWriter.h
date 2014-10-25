//===- TemplightProtobufWriter.h ------ Clang Templight Protobuf Writer -*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TEMPLIGHT_PROTOBUF_WRITER_H
#define LLVM_CLANG_TEMPLIGHT_PROTOBUF_WRITER_H

#include <string>
#include <unordered_map>

namespace llvm {
  class raw_ostream;
}

namespace clang {


struct PrintableTemplightEntryBegin;
struct PrintableTemplightEntryEnd;


class TemplightProtobufWriter {
private:
  
  std::string buffer;
  std::unordered_map< std::string, std::size_t > fileNameMap;
  std::unordered_map< std::string, std::size_t > templateNameMap;
  int compressionMode;
  
  std::size_t createDictionaryEntry(std::string Name);
  std::string printEntryLocation(const std::string& FileName, int Line, int Column);
  std::string printTemplateName(const std::string& Name);
  
public:
  
  TemplightProtobufWriter();
  
  void initialize(const std::string& aSourceName = "");
  std::string& finalize();
  
  void dumpOnStream(llvm::raw_ostream& OS);
  
  void printEntry(const PrintableTemplightEntryBegin& aEntry);
  void printEntry(const PrintableTemplightEntryEnd& aEntry);
  
};


}

#endif



