#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xinstanced_interleaved_buffer>;
template xw::xmaterialize<xthree::xinstanced_interleaved_buffer>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xinstanced_interleaved_buffer>>;
template class xw::xgenerator<xthree::xinstanced_interleaved_buffer>;
template xw::xgenerator<xthree::xinstanced_interleaved_buffer>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xinstanced_interleaved_buffer>>;