#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xclock>;
template xw::xmaterialize<xthree::xclock>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xclock>>;
template class xw::xgenerator<xthree::xclock>;
template xw::xgenerator<xthree::xclock>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xclock>>;