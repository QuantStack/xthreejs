#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcurve>;
template xw::xmaterialize<xthree::xcurve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcurve>>;
template class xw::xgenerator<xthree::xcurve>;
template xw::xgenerator<xthree::xcurve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcurve>>;