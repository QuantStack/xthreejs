#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xgeometry>;
template xw::xmaterialize<xthree::xgeometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xgeometry>>;
template class xw::xgenerator<xthree::xgeometry>;
template xw::xgenerator<xthree::xgeometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xgeometry>>;