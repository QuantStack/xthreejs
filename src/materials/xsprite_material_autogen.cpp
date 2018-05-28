#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xsprite_material>;
template xw::xmaterialize<xthree::xsprite_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xsprite_material>>;
template class xw::xgenerator<xthree::xsprite_material>;
template xw::xgenerator<xthree::xsprite_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xsprite_material>>;