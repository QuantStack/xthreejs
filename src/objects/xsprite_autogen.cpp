#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xsprite>;
template xw::xmaterialize<xthree::xsprite>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xsprite>>;
template class xw::xgenerator<xthree::xsprite>;
template xw::xgenerator<xthree::xsprite>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xsprite>>;