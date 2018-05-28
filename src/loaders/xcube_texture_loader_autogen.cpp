#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcube_texture_loader>;
template xw::xmaterialize<xthree::xcube_texture_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcube_texture_loader>>;
template class xw::xgenerator<xthree::xcube_texture_loader>;
template xw::xgenerator<xthree::xcube_texture_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcube_texture_loader>>;