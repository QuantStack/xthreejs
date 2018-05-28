#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xinterleaved_buffer>;
template xw::xmaterialize<xthree::xinterleaved_buffer>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xinterleaved_buffer>>;
template class xw::xgenerator<xthree::xinterleaved_buffer>;
template xw::xgenerator<xthree::xinterleaved_buffer>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xinterleaved_buffer>>;