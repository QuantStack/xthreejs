#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfog>;
template xw::xmaterialize<xthree::xfog>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfog>>;
template class xw::xgenerator<xthree::xfog>;
template xw::xgenerator<xthree::xfog>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfog>>;