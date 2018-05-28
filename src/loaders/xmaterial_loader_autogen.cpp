#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmaterial_loader>;
template xw::xmaterialize<xthree::xmaterial_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmaterial_loader>>;
template class xw::xgenerator<xthree::xmaterial_loader>;
template xw::xgenerator<xthree::xmaterial_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmaterial_loader>>;