#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xdirect_geometry>;
template xw::xmaterialize<xthree::xdirect_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xdirect_geometry>>;
template class xw::xgenerator<xthree::xdirect_geometry>;
template xw::xgenerator<xthree::xdirect_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xdirect_geometry>>;