#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtexture_loader>;
template xw::xmaterialize<xthree::xtexture_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtexture_loader>>;
template class xw::xgenerator<xthree::xtexture_loader>;
template xw::xgenerator<xthree::xtexture_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtexture_loader>>;