#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xobject_loader>;
template xw::xmaterialize<xthree::xobject_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xobject_loader>>;
template class xw::xgenerator<xthree::xobject_loader>;
template xw::xgenerator<xthree::xobject_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xobject_loader>>;