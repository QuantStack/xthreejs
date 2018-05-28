#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xscene>;
template xw::xmaterialize<xthree::xscene>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xscene>>;
template class xw::xgenerator<xthree::xscene>;
template xw::xgenerator<xthree::xscene>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xscene>>;