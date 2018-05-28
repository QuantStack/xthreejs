#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xedges_geometry>;
template xw::xmaterialize<xthree::xedges_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xedges_geometry>>;
template class xw::xgenerator<xthree::xedges_geometry>;
template xw::xgenerator<xthree::xedges_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xedges_geometry>>;