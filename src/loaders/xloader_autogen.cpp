#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xloader>;
template xw::xmaterialize<xthree::xloader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xloader>>;
template class xw::xgenerator<xthree::xloader>;
template xw::xgenerator<xthree::xloader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xloader>>;