#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xplane_helper>;
template xw::xmaterialize<xthree::xplane_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xplane_helper>>;
template class xw::xgenerator<xthree::xplane_helper>;
template xw::xgenerator<xthree::xplane_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xplane_helper>>;