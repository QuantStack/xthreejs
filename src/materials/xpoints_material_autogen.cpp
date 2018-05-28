#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpoints_material>;
template xw::xmaterialize<xthree::xpoints_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpoints_material>>;
template class xw::xgenerator<xthree::xpoints_material>;
template xw::xgenerator<xthree::xpoints_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpoints_material>>;