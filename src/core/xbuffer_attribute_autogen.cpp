#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbuffer_attribute>;
template xw::xmaterialize<xthree::xbuffer_attribute>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_attribute>>;
template class xw::xgenerator<xthree::xbuffer_attribute>;
template xw::xgenerator<xthree::xbuffer_attribute>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbuffer_attribute>>;