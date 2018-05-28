#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xextrude_geometry>;
template xw::xmaterialize<xthree::xextrude_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xextrude_geometry>>;
template class xw::xgenerator<xthree::xextrude_geometry>;
template xw::xgenerator<xthree::xextrude_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xextrude_geometry>>;