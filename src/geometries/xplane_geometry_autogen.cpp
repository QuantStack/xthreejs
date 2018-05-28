#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xplane_geometry>;
template xw::xmaterialize<xthree::xplane_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xplane_geometry>>;
template class xw::xgenerator<xthree::xplane_geometry>;
template xw::xgenerator<xthree::xplane_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xplane_geometry>>;