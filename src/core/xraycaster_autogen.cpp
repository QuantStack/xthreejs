#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xraycaster>;
template xw::xmaterialize<xthree::xraycaster>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xraycaster>>;
template class xw::xgenerator<xthree::xraycaster>;
template xw::xgenerator<xthree::xraycaster>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xraycaster>>;