#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmesh>;
template xw::xmaterialize<xthree::xmesh>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmesh>>;
template class xw::xgenerator<xthree::xmesh>;
template xw::xgenerator<xthree::xmesh>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmesh>>;