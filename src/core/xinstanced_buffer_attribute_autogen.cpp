#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xinstanced_buffer_attribute>;
template xw::xmaterialize<xthree::xinstanced_buffer_attribute>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xinstanced_buffer_attribute>>;
template class xw::xgenerator<xthree::xinstanced_buffer_attribute>;
template xw::xgenerator<xthree::xinstanced_buffer_attribute>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xinstanced_buffer_attribute>>;