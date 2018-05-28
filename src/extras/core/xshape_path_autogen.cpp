#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xshape_path>;
template xw::xmaterialize<xthree::xshape_path>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xshape_path>>;
template class xw::xgenerator<xthree::xshape_path>;
template xw::xgenerator<xthree::xshape_path>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xshape_path>>;