#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xinterleaved_buffer_attribute>;
template xw::xmaterialize<xthree::xinterleaved_buffer_attribute>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xinterleaved_buffer_attribute>>;
template class xw::xgenerator<xthree::xinterleaved_buffer_attribute>;
template xw::xgenerator<xthree::xinterleaved_buffer_attribute>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xinterleaved_buffer_attribute>>;