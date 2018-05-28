#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xuniform>;
template xw::xmaterialize<xthree::xuniform>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xuniform>>;
template class xw::xgenerator<xthree::xuniform>;
template xw::xgenerator<xthree::xuniform>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xuniform>>;