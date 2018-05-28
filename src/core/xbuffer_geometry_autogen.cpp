#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbuffer_geometry>;
template xw::xmaterialize<xthree::xbuffer_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_geometry>>;
template class xw::xgenerator<xthree::xbuffer_geometry>;
template xw::xgenerator<xthree::xbuffer_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbuffer_geometry>>;