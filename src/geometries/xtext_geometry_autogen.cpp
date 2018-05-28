#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtext_geometry>;
template xw::xmaterialize<xthree::xtext_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtext_geometry>>;
template class xw::xgenerator<xthree::xtext_geometry>;
template xw::xgenerator<xthree::xtext_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtext_geometry>>;