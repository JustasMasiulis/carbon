/////*
//// * Copyright 2017 Justas Masiulis
//// *
//// * Licensed under the Apache License, Version 2.0 (the "License");
//// * you may not use this file except in compliance with the License.
//// * You may obtain a copy of the License at
//// *
//// *     http://www.apache.org/licenses/LICENSE-2.0
//// *
//// * Unless required by applicable law or agreed to in writing, software
//// * distributed under the License is distributed on an "AS IS" BASIS,
//// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//// * See the License for the specific language governing permissions and
//// * limitations under the License.
//// */
//
//#include <fstream>
//#include <string>
//
//constexpr int num_macros = 32;
//char valid_chars[]   = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPADFGHJKLZXCVBNM_";
//static_assert(sizeof(valid_chars) - 1 >= num_macros);
//
// std::string param(int i) { return "_" + std::to_string(i); }
// std::string expanded_param(int i) { return "#" + param(i); }
// std::string expand_args(int n, std::string prefix = {})
//{
//    std::string s;
//    for (int i = 0; i < n; ++i)
//        s += (prefix + valid_chars[i] + ',');
//    if (!s.empty())
//        s.pop_back();
//    return s;
//}
//
//
// int main()
//{
//    std::ofstream out("generated_macros.hpp");
//
//    out << "#pragma once\n"
//        << "#include <tuple>\n\n";
//
//    // generate [1, 32] serialization macros
//    for (int i = 1; i < 33; ++i) {
//        // macro definition
//        out << "#define CARBON_DETAIL_CARBONIZE" << i << "(";
//
//		// macro params
//        for(int j = 0; j < i; ++j)
//            out << valid_chars[j] << ',';
//
//		// get rid of last ,
//		out.seekp(-1);
//        out << ")\\\n";
//
//        // macro body
//        out << "template<class T> struct CARBON_TYPE_NAME { \\\n";
//
//        // member pointers tuple
//        out << "\tconstexpr static auto member_pointers{::carbon::detail::pfr::make_tuple("
//            << expand_args(i, "&T::") << ")};\\\n";
//
//        out << "};\n";
//    }
//
//    out << "\n\n";
//
//    for (int i = 1; i < 33; ++i) {
//        out << "#define CRBN_DETAIL_NAMED_SERIALIZABLE_" << i << "(C";
//        for (int j = 0; j < i; ++j)
//            out << ",_" << j;
//        out << ") ::carbon::serializer<";
//        for (int j = 0; j < i; ++j) {
//            out << "::carbon::named_<CRBN_STR(#_" << j << ")"
//                << ",decltype(&C::_" << j << ")"
//                << ",&C::_" << j << '>';
//            if (j != i - 1)
//                out << ",";
//        }
//        out << ">;\n";
//    }
//}
