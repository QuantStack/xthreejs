#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xlens_flare>;
template xw::xmaterialize<xthree::xlens_flare>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xlens_flare>>;
template class xw::xgenerator<xthree::xlens_flare>;
template xw::xgenerator<xthree::xlens_flare>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xlens_flare>>;