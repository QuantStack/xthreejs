#ifndef XTHREE_MATERIAL_LOADER_HPP
#define XTHREE_MATERIAL_LOADER_HPP

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
    // material_loader declaration
    //

    template<class D>
    class xmaterial_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xmaterial_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using material_loader = xw::xmaterialize<xmaterial_loader>;

    using material_loader_generator = xw::xgenerator<xmaterial_loader>;

    //
    // material_loader implementation
    //


    template <class D>
    inline void xmaterial_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xmaterial_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xmaterial_loader<D>::xmaterial_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmaterial_loader<D>::set_defaults()
    {
        this->_model_name() = "MaterialLoaderModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmaterial_loader>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xmaterial_loader>;
        extern template xw::xmaterialize<xthree::xmaterial_loader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xmaterial_loader>>;
        extern template class xw::xgenerator<xthree::xmaterial_loader>;
        extern template xw::xgenerator<xthree::xmaterial_loader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xmaterial_loader>>;
    #endif
#endif

#endif