#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xlathe_geometry>;
template xw::xmaterialize<xthree::xlathe_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xlathe_geometry>>;
template class xw::xgenerator<xthree::xlathe_geometry>;
template xw::xgenerator<xthree::xlathe_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xlathe_geometry>>;