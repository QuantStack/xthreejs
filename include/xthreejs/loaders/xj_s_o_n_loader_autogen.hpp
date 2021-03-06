#ifndef XTHREE_J_S_O_N_LOADER_HPP
#define XTHREE_J_S_O_N_LOADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // j_s_o_n_loader declaration
    //

    template<class D>
    class xj_s_o_n_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xj_s_o_n_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using j_s_o_n_loader = xw::xmaterialize<xj_s_o_n_loader>;

    using j_s_o_n_loader_generator = xw::xgenerator<xj_s_o_n_loader>;

    //
    // j_s_o_n_loader implementation
    //


    template <class D>
    inline void xj_s_o_n_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xj_s_o_n_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xj_s_o_n_loader<D>::xj_s_o_n_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xj_s_o_n_loader<D>::set_defaults()
    {
        this->_model_name() = "JSONLoaderModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xj_s_o_n_loader>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xj_s_o_n_loader>;
        extern template xw::xmaterialize<xthree::xj_s_o_n_loader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xj_s_o_n_loader>>;
        extern template class xw::xgenerator<xthree::xj_s_o_n_loader>;
        extern template xw::xgenerator<xthree::xj_s_o_n_loader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xj_s_o_n_loader>>;
    #endif
#endif

#endif