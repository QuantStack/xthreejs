#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbox_helper>;
template xw::xmaterialize<xthree::xbox_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbox_helper>>;
template class xw::xgenerator<xthree::xbox_helper>;
template xw::xgenerator<xthree::xbox_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbox_helper>>;