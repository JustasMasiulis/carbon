#pragma once
#include <tuple>

#define CRBN_DETAIL_SERIALIZABLE_1(C,_0)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
};
#define CRBN_DETAIL_SERIALIZABLE_2(C,_0,_1)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
};
#define CRBN_DETAIL_SERIALIZABLE_3(C,_0,_1,_2)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
};
#define CRBN_DETAIL_SERIALIZABLE_4(C,_0,_1,_2,_3)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
};
#define CRBN_DETAIL_SERIALIZABLE_5(C,_0,_1,_2,_3,_4)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
};
#define CRBN_DETAIL_SERIALIZABLE_6(C,_0,_1,_2,_3,_4,_5)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
};
#define CRBN_DETAIL_SERIALIZABLE_7(C,_0,_1,_2,_3,_4,_5,_6)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
};
#define CRBN_DETAIL_SERIALIZABLE_8(C,_0,_1,_2,_3,_4,_5,_6,_7)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
};
#define CRBN_DETAIL_SERIALIZABLE_9(C,_0,_1,_2,_3,_4,_5,_6,_7,_8)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
};
#define CRBN_DETAIL_SERIALIZABLE_10(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
};
#define CRBN_DETAIL_SERIALIZABLE_11(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
};
#define CRBN_DETAIL_SERIALIZABLE_12(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
};
#define CRBN_DETAIL_SERIALIZABLE_13(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
};
#define CRBN_DETAIL_SERIALIZABLE_14(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
};
#define CRBN_DETAIL_SERIALIZABLE_15(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
};
#define CRBN_DETAIL_SERIALIZABLE_16(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
};
#define CRBN_DETAIL_SERIALIZABLE_17(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
};
#define CRBN_DETAIL_SERIALIZABLE_18(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
};
#define CRBN_DETAIL_SERIALIZABLE_19(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
};
#define CRBN_DETAIL_SERIALIZABLE_20(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
};
#define CRBN_DETAIL_SERIALIZABLE_21(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
};
#define CRBN_DETAIL_SERIALIZABLE_22(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
};
#define CRBN_DETAIL_SERIALIZABLE_23(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
};
#define CRBN_DETAIL_SERIALIZABLE_24(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
};
#define CRBN_DETAIL_SERIALIZABLE_25(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
};
#define CRBN_DETAIL_SERIALIZABLE_26(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
};
#define CRBN_DETAIL_SERIALIZABLE_27(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25,&_xCT::_26)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
	decltype(auto) _26(){return _this_->_xCT::_26;}\
};
#define CRBN_DETAIL_SERIALIZABLE_28(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25,&_xCT::_26,&_xCT::_27)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
	decltype(auto) _26(){return _this_->_xCT::_26;}\
	decltype(auto) _27(){return _this_->_xCT::_27;}\
};
#define CRBN_DETAIL_SERIALIZABLE_29(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25,&_xCT::_26,&_xCT::_27,&_xCT::_28)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
	decltype(auto) _26(){return _this_->_xCT::_26;}\
	decltype(auto) _27(){return _this_->_xCT::_27;}\
	decltype(auto) _28(){return _this_->_xCT::_28;}\
};
#define CRBN_DETAIL_SERIALIZABLE_30(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25,&_xCT::_26,&_xCT::_27,&_xCT::_28,&_xCT::_29)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
	decltype(auto) _26(){return _this_->_xCT::_26;}\
	decltype(auto) _27(){return _this_->_xCT::_27;}\
	decltype(auto) _28(){return _this_->_xCT::_28;}\
	decltype(auto) _29(){return _this_->_xCT::_29;}\
};
#define CRBN_DETAIL_SERIALIZABLE_31(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25,&_xCT::_26,&_xCT::_27,&_xCT::_28,&_xCT::_29,&_xCT::_30)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
	decltype(auto) _26(){return _this_->_xCT::_26;}\
	decltype(auto) _27(){return _this_->_xCT::_27;}\
	decltype(auto) _28(){return _this_->_xCT::_28;}\
	decltype(auto) _29(){return _this_->_xCT::_29;}\
	decltype(auto) _30(){return _this_->_xCT::_30;}\
};
#define CRBN_DETAIL_SERIALIZABLE_32(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31)template<class _xCT, class _xCA> struct carbon_type {\
	_xCT* _this_;\
	_xCA _archive_;\
	carbon_type(_xCT* t, _xCA a) : _this_(t), _archive_(a) {}\
	constexpr static auto member_pointers{std::make_tuple(&_xCT::_0,&_xCT::_1,&_xCT::_2,&_xCT::_3,&_xCT::_4,&_xCT::_5,&_xCT::_6,&_xCT::_7,&_xCT::_8,&_xCT::_9,&_xCT::_10,&_xCT::_11,&_xCT::_12,&_xCT::_13,&_xCT::_14,&_xCT::_15,&_xCT::_16,&_xCT::_17,&_xCT::_18,&_xCT::_19,&_xCT::_20,&_xCT::_21,&_xCT::_22,&_xCT::_23,&_xCT::_24,&_xCT::_25,&_xCT::_26,&_xCT::_27,&_xCT::_28,&_xCT::_29,&_xCT::_30,&_xCT::_31)};\
	decltype(auto) _0(){return _this_->_xCT::_0;}\
	decltype(auto) _1(){return _this_->_xCT::_1;}\
	decltype(auto) _2(){return _this_->_xCT::_2;}\
	decltype(auto) _3(){return _this_->_xCT::_3;}\
	decltype(auto) _4(){return _this_->_xCT::_4;}\
	decltype(auto) _5(){return _this_->_xCT::_5;}\
	decltype(auto) _6(){return _this_->_xCT::_6;}\
	decltype(auto) _7(){return _this_->_xCT::_7;}\
	decltype(auto) _8(){return _this_->_xCT::_8;}\
	decltype(auto) _9(){return _this_->_xCT::_9;}\
	decltype(auto) _10(){return _this_->_xCT::_10;}\
	decltype(auto) _11(){return _this_->_xCT::_11;}\
	decltype(auto) _12(){return _this_->_xCT::_12;}\
	decltype(auto) _13(){return _this_->_xCT::_13;}\
	decltype(auto) _14(){return _this_->_xCT::_14;}\
	decltype(auto) _15(){return _this_->_xCT::_15;}\
	decltype(auto) _16(){return _this_->_xCT::_16;}\
	decltype(auto) _17(){return _this_->_xCT::_17;}\
	decltype(auto) _18(){return _this_->_xCT::_18;}\
	decltype(auto) _19(){return _this_->_xCT::_19;}\
	decltype(auto) _20(){return _this_->_xCT::_20;}\
	decltype(auto) _21(){return _this_->_xCT::_21;}\
	decltype(auto) _22(){return _this_->_xCT::_22;}\
	decltype(auto) _23(){return _this_->_xCT::_23;}\
	decltype(auto) _24(){return _this_->_xCT::_24;}\
	decltype(auto) _25(){return _this_->_xCT::_25;}\
	decltype(auto) _26(){return _this_->_xCT::_26;}\
	decltype(auto) _27(){return _this_->_xCT::_27;}\
	decltype(auto) _28(){return _this_->_xCT::_28;}\
	decltype(auto) _29(){return _this_->_xCT::_29;}\
	decltype(auto) _30(){return _this_->_xCT::_30;}\
	decltype(auto) _31(){return _this_->_xCT::_31;}\
};


#define CRBN_DETAIL_NAMED_SERIALIZABLE_1(C,_0) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_2(C,_0,_1) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_3(C,_0,_1,_2) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_4(C,_0,_1,_2,_3) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_5(C,_0,_1,_2,_3,_4) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_6(C,_0,_1,_2,_3,_4,_5) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_7(C,_0,_1,_2,_3,_4,_5,_6) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_8(C,_0,_1,_2,_3,_4,_5,_6,_7) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_9(C,_0,_1,_2,_3,_4,_5,_6,_7,_8) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_10(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_11(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_12(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_13(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_14(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_15(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_16(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_17(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_18(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_19(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_20(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_21(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_22(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_23(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_24(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_25(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_26(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_27(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>,::carbon::named_<CRBN_STR(#_26),decltype(&C::_26),&C::_26>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_28(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>,::carbon::named_<CRBN_STR(#_26),decltype(&C::_26),&C::_26>,::carbon::named_<CRBN_STR(#_27),decltype(&C::_27),&C::_27>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_29(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>,::carbon::named_<CRBN_STR(#_26),decltype(&C::_26),&C::_26>,::carbon::named_<CRBN_STR(#_27),decltype(&C::_27),&C::_27>,::carbon::named_<CRBN_STR(#_28),decltype(&C::_28),&C::_28>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_30(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>,::carbon::named_<CRBN_STR(#_26),decltype(&C::_26),&C::_26>,::carbon::named_<CRBN_STR(#_27),decltype(&C::_27),&C::_27>,::carbon::named_<CRBN_STR(#_28),decltype(&C::_28),&C::_28>,::carbon::named_<CRBN_STR(#_29),decltype(&C::_29),&C::_29>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_31(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>,::carbon::named_<CRBN_STR(#_26),decltype(&C::_26),&C::_26>,::carbon::named_<CRBN_STR(#_27),decltype(&C::_27),&C::_27>,::carbon::named_<CRBN_STR(#_28),decltype(&C::_28),&C::_28>,::carbon::named_<CRBN_STR(#_29),decltype(&C::_29),&C::_29>,::carbon::named_<CRBN_STR(#_30),decltype(&C::_30),&C::_30>>;
#define CRBN_DETAIL_NAMED_SERIALIZABLE_32(C,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31) ::carbon::serializer<::carbon::named_<CRBN_STR(#_0),decltype(&C::_0),&C::_0>,::carbon::named_<CRBN_STR(#_1),decltype(&C::_1),&C::_1>,::carbon::named_<CRBN_STR(#_2),decltype(&C::_2),&C::_2>,::carbon::named_<CRBN_STR(#_3),decltype(&C::_3),&C::_3>,::carbon::named_<CRBN_STR(#_4),decltype(&C::_4),&C::_4>,::carbon::named_<CRBN_STR(#_5),decltype(&C::_5),&C::_5>,::carbon::named_<CRBN_STR(#_6),decltype(&C::_6),&C::_6>,::carbon::named_<CRBN_STR(#_7),decltype(&C::_7),&C::_7>,::carbon::named_<CRBN_STR(#_8),decltype(&C::_8),&C::_8>,::carbon::named_<CRBN_STR(#_9),decltype(&C::_9),&C::_9>,::carbon::named_<CRBN_STR(#_10),decltype(&C::_10),&C::_10>,::carbon::named_<CRBN_STR(#_11),decltype(&C::_11),&C::_11>,::carbon::named_<CRBN_STR(#_12),decltype(&C::_12),&C::_12>,::carbon::named_<CRBN_STR(#_13),decltype(&C::_13),&C::_13>,::carbon::named_<CRBN_STR(#_14),decltype(&C::_14),&C::_14>,::carbon::named_<CRBN_STR(#_15),decltype(&C::_15),&C::_15>,::carbon::named_<CRBN_STR(#_16),decltype(&C::_16),&C::_16>,::carbon::named_<CRBN_STR(#_17),decltype(&C::_17),&C::_17>,::carbon::named_<CRBN_STR(#_18),decltype(&C::_18),&C::_18>,::carbon::named_<CRBN_STR(#_19),decltype(&C::_19),&C::_19>,::carbon::named_<CRBN_STR(#_20),decltype(&C::_20),&C::_20>,::carbon::named_<CRBN_STR(#_21),decltype(&C::_21),&C::_21>,::carbon::named_<CRBN_STR(#_22),decltype(&C::_22),&C::_22>,::carbon::named_<CRBN_STR(#_23),decltype(&C::_23),&C::_23>,::carbon::named_<CRBN_STR(#_24),decltype(&C::_24),&C::_24>,::carbon::named_<CRBN_STR(#_25),decltype(&C::_25),&C::_25>,::carbon::named_<CRBN_STR(#_26),decltype(&C::_26),&C::_26>,::carbon::named_<CRBN_STR(#_27),decltype(&C::_27),&C::_27>,::carbon::named_<CRBN_STR(#_28),decltype(&C::_28),&C::_28>,::carbon::named_<CRBN_STR(#_29),decltype(&C::_29),&C::_29>,::carbon::named_<CRBN_STR(#_30),decltype(&C::_30),&C::_30>,::carbon::named_<CRBN_STR(#_31),decltype(&C::_31),&C::_31>>;
