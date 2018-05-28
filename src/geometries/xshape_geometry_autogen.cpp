#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xshape_geometry>;
template xw::xmaterialize<xthree::xshape_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xshape_geometry>>;
template class xw::xgenerator<xthree::xshape_geometry>;
template xw::xgenerator<xthree::xshape_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xshape_geometry>>;