#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpoints>;
template xw::xmaterialize<xthree::xpoints>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpoints>>;
template class xw::xgenerator<xthree::xpoints>;
template xw::xgenerator<xthree::xpoints>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpoints>>;