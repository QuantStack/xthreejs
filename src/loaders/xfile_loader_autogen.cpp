#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfile_loader>;
template xw::xmaterialize<xthree::xfile_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfile_loader>>;
template class xw::xgenerator<xthree::xfile_loader>;
template xw::xgenerator<xthree::xfile_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfile_loader>>;