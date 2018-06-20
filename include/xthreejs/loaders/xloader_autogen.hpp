#ifndef XTHREE_LOADER_HPP
#define XTHREE_LOADER_HPP

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
    // loader declaration
    //

    template<class D>
    class xloader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xloader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using loader = xw::xmaterialize<xloader>;

    using loader_generator = xw::xgenerator<xloader>;

    //
    // loader implementation
    //


    template <class D>
    inline void xloader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xloader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xloader<D>::xloader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xloader<D>::set_defaults()
    {
        this->_model_name() = "LoaderModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xloader>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xloader>;
        extern template xw::xmaterialize<xthree::xloader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xloader>>;
        extern template class xw::xgenerator<xthree::xloader>;
        extern template xw::xgenerator<xthree::xloader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xloader>>;
    #endif
#endif

#endif