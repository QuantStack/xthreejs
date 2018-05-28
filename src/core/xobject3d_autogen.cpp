#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xobject3d_base>;
template xw::xmaterialize<xthree::xobject3d_base>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xobject3d_base>>;
template class xw::xgenerator<xthree::xobject3d_base>;
template xw::xgenerator<xthree::xobject3d_base>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xobject3d_base>>;