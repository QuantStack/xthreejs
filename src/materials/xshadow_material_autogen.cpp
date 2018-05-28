#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xshadow_material>;
template xw::xmaterialize<xthree::xshadow_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xshadow_material>>;
template class xw::xgenerator<xthree::xshadow_material>;
template xw::xgenerator<xthree::xshadow_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xshadow_material>>;