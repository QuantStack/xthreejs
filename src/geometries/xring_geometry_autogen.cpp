#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xring_geometry>;
template xw::xmaterialize<xthree::xring_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xring_geometry>>;
template class xw::xgenerator<xthree::xring_geometry>;
template xw::xgenerator<xthree::xring_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xring_geometry>>;