#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcurve_path>;
template xw::xmaterialize<xthree::xcurve_path>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcurve_path>>;
template class xw::xgenerator<xthree::xcurve_path>;
template xw::xgenerator<xthree::xcurve_path>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcurve_path>>;