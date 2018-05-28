#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtexture>;
template xw::xmaterialize<xthree::xtexture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtexture>>;
template class xw::xgenerator<xthree::xtexture>;
template xw::xgenerator<xthree::xtexture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtexture>>;